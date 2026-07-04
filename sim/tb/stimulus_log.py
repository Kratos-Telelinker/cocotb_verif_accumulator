import csv

_log_file = None
_writer = None

def init_stimulus_log(filename="stimulus_log.csv"):
    global _log_file, _writer
    _log_file = open(filename, "w", newline="")
    _writer = csv.writer(_log_file)
    _writer.writerow(["channel", "a", "b", "valid_in", "rst"])

def log_sample(sample):
    if _writer is None:
        return
    _writer.writerow([
        sample["channel"],
        sample["a"],
        sample["b"],
        sample["valid_in"],
        sample["rst"],
    ])

def close_stimulus_log():
    global _log_file, _writer
    if _log_file is not None:
        _log_file.close()
    _log_file = None
    _writer = None
