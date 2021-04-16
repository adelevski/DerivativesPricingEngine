




class BSM():

    def __init__(self, ass, strk, rfr, vol, yrs, steps, sims):
        self.assetPrice = ass
        self.strikePrice = strk
        self.riskFreeRate = rfr
        self.volatility = vol
        self.years = yrs
        self.steps = steps
        self.simulations = sims

    def logNormalRandomWalk(self):
        pass

    def printDetails(self):
        print(f"Asset: {self.assetPrice}\n" +  
              f"Strike: {self.strikePrice}\n"
              f"RFR: {self.riskFreeRate}\n"
              f"Volatility: {self.volatility}\n"
              f"Years: {self.years}\n"
              f"Steps: {self.steps}\n"
              f"Simulations: {self.simulations}\n")

bsm = BSM(100, 110, 0.05, 0.2, 1, 100, 100000)


bsm.printDetails()