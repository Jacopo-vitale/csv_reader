import pandas as pd
import numpy as np

for i in range(6):
    df = pd.DataFrame(
        np.random.rand(200,6)
    )

    df.to_csv(f'dummy_csv{i+1}.csv',index=False,header=False)


df1 = pd.read_csv("dummy_csv4.csv",names=['col1','col2','col3','col4','col5','col6'])

print(df1.head())

df1.query("col3 > 0.5 and col1 >= 0.7",inplace=True)

print(df1.head())