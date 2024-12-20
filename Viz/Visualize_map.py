import geopandas as gpd
import pandas as pd 
import matplotlib.pyplot as plt

geo_jsons = [
    'https://geodata.ucdavis.edu/gadm/gadm4.1/json/gadm41_DNK_0.json',
]

df_locations = pd.read_csv('dataset.csv')
print(df_locations)
geo_df_total = pd.DataFrame()

for geo_json in geo_jsons:
    geo_df = gpd.read_file(geo_json)
    print(geo_df)
    geo_df_total = gpd.GeoDataFrame(pd.concat( [geo_df_total, geo_df], ignore_index=True) )

geo_df_total.head()

geo_df_total.plot()

geo_axes = geo_df_total.plot()


stations = {
    'name':"",
    'x': [],
    'y': [],
}


for index, local in df_locations.iterrows():
    coords = (local['lat'],local['lon'])
    x = float(coords[1])
    y = float(coords[0])

    stations['x'].append(x)
    stations['y'].append(y)

print(len(stations))


geo_axes = geo_df_total.plot(facecolor='#eaeaea', edgecolor='#fff', linewidth=.2, figsize=(5, 8), zorder=0)

marker_size = 50

#geo_axes.plot(lines['x'], lines['y'], c='teal', linewidth=.5, zorder=2)
geo_axes.scatter(stations['x'], stations['y'], c='dimgrey', s=marker_size, marker='^', zorder=3, edgecolor='white')

plt.gcf().axes[0].axis('off')
plt.savefig('map_with_markers_and_lines.jpg')

