import cocotb

class Agent:
    def __init__(self, name, driver, monitor):
        self.name = name
        self.driver = driver
        self.monitor = monitor

    async def start(self):
        # Start BOTH monitor and driver
        cocotb.start_soon(self.monitor.start())
        cocotb.start_soon(self.driver.start())

    async def reset(self):
        await self.driver.reset()

    async def send(self, txn):
        await self.driver.send(txn)


# import cocotb

# class Agent:
#     def __init__(self, name, driver, monitor):
#         self.name = name
#         self.driver = driver
#         self.monitor = monitor

#     async def start(self):
#         cocotb.start_soon(self.driver.start())
#         cocotb.start_soon(self.monitor.start())

#     async def reset(self):
#         await self.driver.reset()

#     async def send(self, txn):
#         await self.driver.send(txn)