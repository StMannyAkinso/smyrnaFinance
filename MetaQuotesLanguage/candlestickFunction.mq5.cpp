// Define a function that takes the symbol, timeframe, and number of candles to check
bool CheckCandlesticks(string symbol, ENUM_TIMEFRAMES timeframe, int numCandles)
{
    // Declare variables for the candlesticks
    double candleBody, candleUpper, candleLower;
    int i;
    // Loop through the last 'numCandles' bars and check the candlestick patterns
    for (i = 0; i < numCandles; i++)
    {
        // Calculate the dimensions of the candlestick
        candleBody = MathAbs(Open[symbol][timeframe][i] - Close[symbol][timeframe][i]);
        candleUpper = High[symbol][timeframe][i] - MathMax(Open[symbol][timeframe][i], Close[symbol][timeframe][i]);
        candleLower = MathMin(Open[symbol][timeframe][i], Close[symbol][timeframe][i]) - Low[symbol][timeframe][i];

        // Check for a bullish engulfing pattern
        if (candleBody > candleUpper + candleLower &&
            Close[symbol][timeframe][i] > Open[symbol][timeframe][i] &&
            Open[symbol][timeframe][i + 1] > Close[symbol][timeframe][i + 1] &&
            Close[symbol][timeframe][i + 1] > Open[symbol][timeframe][i] &&
            Open[symbol][timeframe][i] > Close[symbol][timeframe][i + 1])
        {
            return true;
        } // This was the end of the if statement for bullish engulfing pattern

        // Check for a bearish engulfing pattern
        if (candleBody > candleUpper + candleLower &&
            Open[symbol][timeframe][i] > Close[symbol][timeframe][i] &&
            Close[symbol][timeframe][i + 1] > Open[symbol][timeframe][i + 1] &&
            Open[symbol][timeframe][i + 1] > Close[symbol][timeframe][i] &&
            Close[symbol][timeframe][i + 1] < Open[symbol][timeframe][i])
        {
            return true;
        } // This was the end of the if statement for bearish engulfing pattern
    }

    // If no patterns were found, return false
    return false;
}