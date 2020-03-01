#Import libraries
import requests
import os
from datetime import datetime

#Get the URL ticker to get the .json files of the crypto currencies
TICKER_API_URL = 'https://api.coinmarketcap.com/v1/ticker/'
def get_latest_crypto_price( crypto ):
    response = requests.get(TICKER_API_URL+crypto)
    response_json = response.json()
    # Convert the price to a floating point number
    return float(response_json[0]['price_usd'])

BITCOIN_PRICE_THRESHOLD = 1000
def main():
  #Set last_price to -1 to indicate the last price hasn't been recorded yet
  last_price = -1
  while True:
    price_ltc = get_latest_crypto_price("litecoin")
    price_btc = get_latest_crypto_price("bitcoin")
    price_eth = get_latest_crypto_price("ethereum")
    price_xrp = get_latest_crypto_price("xrp")
    os.system("clear")
    print("Bitcoin's Price is:", price_btc)
    print("Litecoin's Price is:", price_ltc)
    print("Ethereum's Price is:", price_eth)
    print("XRP(Ripple)'s price is:", price_xrp)
    '''now = datetime.now()
    now.strftime("%Y-%m-%d %H:%M")#Returns format (YYYY-mm-DDTHH:MM:SS.MS)
    #Check if the crypto currency price is less than your threshold
    if price < BITCOIN_PRICE_THRESHOLD:
      print('The Crypto is lower than your threshold')
    #Print the price of bitcoin only if the current price is different from the last price
    if price != last_price:
      print(now.isoformat() , ' Bitcoin price = ',price)
      last_price = price #update last_price to be the current price'''

main();
