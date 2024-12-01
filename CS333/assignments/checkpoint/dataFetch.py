import requests
import json

def getIntraday(ticker):
    url = 'https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY&symbol=' + ticker + '&interval=5min&apikey=CSODLOR6KOZ1HUKT'
    r = requests.get(url)
    data = r.json()

    return data


def getOverview(ticker):
    overview_url = 'https://www.alphavantage.co/query?function=OVERVIEW&' + ticker + '=IBM&apikey=CSODLOR6KOZ1HUKT'
    r = requests.get(overview_url)
    overview_data = json.dumps(r.json())

    Json_String = json.loads(data)
    #Company table data
    Description = Json_String['Description'] 
    Sector = Json_String['Sector'] 
    Industry = Json_String['Industry'] 
    Name = Json_String['Name'] 
    Address = Json_String['Address'] 
    
    #Stock table data
    Ticker = Json_String['Symbol'] 
    Stock_Type = Json_String['AssetType'] 
    Currency = Json_String['Currency'] 

#date format: YEAR-MONTH-DAY: ####-##-##
def getDaily(ticker):
    url = 'https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=IBM&apikey=CSODLOR6KOZ1HUKT'
    r = requests.get(url)
    data = json.loads(json.dumps(r.json()))

    meta_data = data['Meta Data']
    time_series = data['Time Series (Daily)']
    last_refreshed = meta_data['3. Last Refreshed']

    date_in = last_refreshed #change to whatever date is needed (probably use 6 weeks-ish in the database)
    parsed_data = time_series[date_in]
    open = parsed_data['1. open']
    high = parsed_data['2. high']
    low = parsed_data['3. low']
    close = parsed_data['4. close']
    volume = parsed_data['5. volume']

url = 'https://www.alphavantage.co/query?function=DIVIDENDS&symbol=IBM&apikey=ARSHRW37KDJ9WEOP'
r = requests.get(url)
data = json.loads(json.dumps(r.json()))
print(data)





#need dividend amount, payment date, declaration data





