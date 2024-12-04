import requests
import json

# Define the base URL and endpoint
base_url = "https://www.rejseplanen.dk/api/"
endpoint = "departureBoard" #"journeyDetail"

# Define the parameters (replace YOUR_ACCESS_ID with your actual API key)
params = {
    "accessId": "6b2d0ad1-44e1-49df-a746-82580093194c",
    "format": "json",
    "id":"A=1@O=K\u00f8benhavn H@X=12565562@Y=55673063@U=86@L=8600626@"
    #"id": "2|#VN#1#ST#1732276819#PI#0#ZI#2545#TA#0#DA#161224#1S#8600669#1T#813#LS#8600719#LT#1006#PU#86#RT#1#CA#004#ZE#2535#ZB#Re 2535#PC#2#FR#8600669#FT#813#TO#8600719#TT#1006#"
    #"id": "2|#VN#1#ST#1732276819#PI#0#ZI#567#TA#0#DA#221224#1S#8600053#1T#245#LS#8600626#LT#610#PU#86#RT#1#CA#001#ZE#102#ZB#IC    102#PC#0#FR#8600053#FT#245#TO#8600626#TT#610#"#"operators":"DSB",
    #"match":"Re 2535",
    #"lineId": "039_117411_070",
    #"date":"2024-11-23"
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
        with open(f'response_data_{endpoint}_2.json', 'w') as file:
            json.dump(data, file, indent=4)
        
        print("Data written to response_data.json")
    except requests.exceptions.JSONDecodeError:
        print("Response content is not valid JSON")
else:
    print(f"Error: {response.status_code}")
    print(response.text)