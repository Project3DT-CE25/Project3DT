import math
import pandas as pd
import folium
from folium import Choropleth, Circle, Marker
from folium.plugins import HeatMap, MarkerCluster
excel_file = 'จำนวนประชากร_lat_long - Copy2.xlsx'
df = pd.read_excel(excel_file)

m1 = folium.Map(location=[15.0000, 100.0000], zoom_start=5) # [ละติจูด,ลองติดจูด] และการซูมลำดับ 5
# peopleMax = [200000] 
# peopleMin = [100000]        
condi1 = ['P6']
condi2 = ['P8']
# df['People'] = df['People'].astype(int)  
# print(df)      
# df1 = df[df['People'] <= 200000 ] 
# print(df1)
# df2 = df1[df1['People'] >= 100000 ]
# print(df)
# df = df[df['People'] > 200000]
# print(df)
# index = df.index
# number_of_rows = len(index)
# print(number_of_rows)
sum1 = df[df['People'] > 200000]  
sum2 = df[df['People'] <= 200000] 
sum2 = sum2[sum2['People'] >= 100000]
sum3 = df[df['People'] < 100000] 
# print(sum1)
index1 = sum1.index
index2 = sum2.index
index3 = sum3.index
number_of_rows1 = len(index1) 
number_of_rows2 = len(index2)
number_of_rows3 = len(index3)

p6sum1 = sum1[sum1['Screen'].isin(condi1)] 
p8sum1 = sum1[sum1['Screen'].isin(["P8"])] 
p6sum2 = sum2[sum2['Screen'].isin(["P6"])] 
p8sum2 = sum2[sum2['Screen'].isin(["P8"])]
p6sum3 = sum3[sum3['Screen'].isin(["P6"])] 
p8sum3 = sum3[sum3['Screen'].isin(["P8"])] 
print(p6sum3)
indexp61 = p6sum1.index
indexp62 = p6sum2.index
indexp63 = p6sum3.index
indexp81 = p8sum1.index
indexp82 = p8sum2.index
indexp83 = p8sum3.index

number_of_rowsp61 = len(indexp61) 
number_of_rowsp62 = len(indexp62)
number_of_rowsp63 = len(indexp63)
number_of_rowsp81 = len(indexp81) 
number_of_rowsp82 = len(indexp82)
number_of_rowsp83 = len(indexp83)
print(number_of_rowsp63)
print(number_of_rowsp61)  # Test comment
