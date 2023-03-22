// A function that takes the symbol, timeframe and period for the Moving Average 
double MovingAverage(string symbol, ENUM_TIMEFRAMES timeframe, int period)
{
    // Declare variables for the Moving Average calculation
    double ma = 0;
    double sum = 0;
    int i;
    
    // Loop through the last 'period' bars and calculate the Moving Average
    for(i = 0; i < period; i++)
    {
        sum += Close[symbol][timeframe][i];
    }
    
    ma = sum / period;
    
    // Return the Moving Average value
    return ma;
}

void OnTick()
{
    // Get the Moving Average value for the last 50 bars on the EURUSD M30 chart
    double ma = MovingAverage("EURUSD", PERIOD_M30, 50);
    
    // Check if the current price is above or below the Moving Average
    if(Bid > ma)
    {
        // Place a Buy trade
        OrderSend("EURUSD", OP_BUY, 0.1, Ask, 10, 0, 0, "", 0, 0, Green);
    }
    else if(Bid < ma)
    {
        // Place a Sell trade
        OrderSend("EURUSD", OP_SELL, 0.1, Bid, 10, 0, 0, "", 0, 0, Red);
    }
}
