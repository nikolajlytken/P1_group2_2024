import requests
import json

# Define the base URL and endpoint
base_url = "https://www.rejseplanen.dk/api/"
endpoint = "trainsearch"

#"id": "A=4@O=K\u00f8benhavns Hovedbaneg\u00e5rd, Anden bygning, K\u00f8benhavn@X=12564672@Y=55672776@U=104@L=990032628@B=1@p=1731313114@",
#"id": "A=1@O=Roskilde St.@X=12088478@Y=55638617@U=86@L=860061705@B=1@p=1732276819@"
end = 860061706

# Define the parameters (replace YOUR_ACCESS_ID with your actual API key)
params = {
    "accessId": "",
    "format": "json",
    "match":"Re 1533"
    # "originId":"A=4@O=K\u00f8benhavns Hovedbaneg\u00e5rd, Anden bygning, K\u00f8benhavn@X=12564672@Y=55672776@U=104@L=990032628@B=1@p=1731313114@",
    # "destId":"A=1@O=Roskilde St.@X=12088478@Y=55638617@U=86@L=860061705@B=1@p=1732276819@"
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
        
        print("Data written to response_data.json")
    except requests.exceptions.JSONDecodeError:
        print("Response content is not valid JSON")
else:
    print(f"Error: {response.status_code}")
    print(response.text)