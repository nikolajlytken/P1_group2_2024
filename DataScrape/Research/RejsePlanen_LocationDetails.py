import requests
import json

# Define the base URL and endpoint
base_url = "https://www.rejseplanen.dk/api/"
endpoint = "location.details"

with open('extId.json',) as f: 
    input = json.load(f)

#for extID in input: 
# Define the parameters (replace YOUR_ACCESS_ID with your actual API key)
params = {
    "accessId": "6b2d0ad1-44e1-49df-a746-82580093194c",
    "format": "json",
    "extId":"1273"
    #"match":"Re"
}

# Construct the full URL
url = f"{base_url}{endpoint}"
# Make the GET request
response = requests.get(url, params=params)
# Check the response status
if response.status_code == 200:
    try:
        # Parse the JSON response
        data = response.json()  # Use response.text if the response is XML
        # Write the data to a file
        with open(f'response_data_{endpoint}.json', 'w') as file:
            json.dump(data, file, indent=4)
        
        print(f"Data written to response_data_{endpoint}.json")
    except requests.exceptions.JSONDecodeError:
        print("Response content is not valid JSON")
else:
    print(f"Error: {response.status_code}")
    print(response.text)