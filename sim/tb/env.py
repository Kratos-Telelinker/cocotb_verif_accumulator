import cocotb
from .stimulus_log import init_stimulus_log, log_sample, close_stimulus_log

class Env:
    def __init__(self, agent_a, agent_b, scoreboard, coverage=None):
        self.agent_a = agent_a
        self.agent_b = agent_b
        self.scoreboard = scoreboard
        self.coverage = coverage

    def _cb(self, sample):
        self.scoreboard.compare(sample)
        log_sample(sample)
        if self.coverage is not None:
            self.coverage.sample(sample)

    async def start(self):
        init_stimulus_log("stimulus_log.csv")

        if self.agent_a is not None:
            self.agent_a.monitor.callback = self._cb
            cocotb.start_soon(self.agent_a.monitor.start())

        if self.agent_b is not None:
            self.agent_b.monitor.callback = self._cb
            cocotb.start_soon(self.agent_b.monitor.start())

    def finalize(self):
        print(">>> EXPORTING COVERAGE FROM ENV")
        self.scoreboard.finalize()

        if self.coverage is not None:
            # 1. Export per‑test coverage
            self.coverage.export_yaml("regression_results/functional_coverage.yaml")
            self.coverage.export_xml("regression_results/functional_coverage.xml")

            # 2. Export regression‑level merged coverage
            self.coverage.export_regression(
                "regression_results/functional_coverage_regression.yaml",
                "regression_results/functional_coverage_regression.xml"
            )

            # 3. Print summary
            self.coverage.summary()

            # 4. Enforce coverage threshold (Chunk 14)
            self.coverage.check_thresholds(min_pct=75.0)

    close_stimulus_log()


