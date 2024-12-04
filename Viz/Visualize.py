# import osmnx as ox
# import networkx as nx
# import matplotlib.pyplot as plt

# # Define the place of interest
# place_name = "Copenhagen, Denmark"

# # Retrieve the railway network
# G = ox.graph_from_place(place_name, network_type='all', custom_filter='["railway"~"station|rail"]')

# # Plot the graph
# fig, ax = ox.plot_graph(G, node_size=10, node_color='red', edge_color='black', edge_linewidth=1.0)


import geopandas as gpd
import pandas as pd 
import matplotlib.pyplot as plt

geo_jsons = [
    'https://geodata.ucdavis.edu/gadm/gadm4.1/json/gadm41_DNK_0.json',
]



geo_df_total = pd.DataFrame()

for geo_json in geo_jsons:
    geo_df = gpd.read_file(geo_json)
    print(geo_df)
    geo_df_total = gpd.GeoDataFrame(pd.concat( [geo_df_total, geo_df], ignore_index=True) )

geo_df_total.head()

geo_df_total.plot()

geo_axes = geo_df_total.plot()
#geo_axes.scatter([20], [63], c='red')

plt.gcf().axes[0].axis('off')
plt.savefig('map_with_single_marker_test.jpg')