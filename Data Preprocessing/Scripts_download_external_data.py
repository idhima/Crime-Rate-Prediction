import requests

def download_weather_data():
    url = "https://api.weather.com/v1/data_endpoint"
    # Call weather API to get historical data
    response = requests.get(url)
    if response.status_code == 200:
        with open('data/weather_data.csv', 'w') as f:
            f.write(response.text)
    else:
        print("Error downloading data")

def download_socioeconomic_data():
    url = "https://datahub.io/socioeconomic/indicators"
    response = requests.get(url)
    if response.status_code == 200:
        with open('data/socioeconomic_data.csv', 'w') as f:
            f.write(response.text)
    else:
        print("Error downloading data")

download_weather_data()
download_socioeconomic_data()
