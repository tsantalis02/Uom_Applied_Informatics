# Stergios Tsantalis, iis21125

import pandas as pd
from sklearn import preprocessing
from imblearn.under_sampling import EditedNearestNeighbours
from imblearn.under_sampling import CondensedNearestNeighbour

def NormalizeValues(data):
    df = pd.DataFrame(data)
    del_column = df['class']
    del df['class']
    d = preprocessing.normalize(df)
    norm_df = pd.DataFrame(d)
    norm_df.columns = df.columns 
    norm_df['class'] = del_column
    return norm_df

def ENNalgorithm(data,num_neighbors):
    df2 = pd.DataFrame(data)
    X = df2.drop(['class'],axis=1)
    y = df2['class'].values
    enn = EditedNearestNeighbours(n_neighbors=num_neighbors)
    X_res,y_res = enn.fit_resample(X,y)
    X_res['class'] = y_res
    return X_res

def IB2algorithm(data):
    df3 = pd.DataFrame(data)
    X = df3.drop(['class'], axis = 1)
    y = df3['class'].values
    ib2 = CondensedNearestNeighbour()
    X_res,y_res = ib2.fit_resample(X,y)
    X_res['class'] = y_res
    return X_res   
    
    
# Normalize values for letter-recognition.csv

letter_recognition_data = pd.read_csv(r"C:\Users\UserA\Desktop\pp1\letter-recognition.csv")
norm_df = NormalizeValues(letter_recognition_data)
norm_df.to_csv(r"C:\Users\UserA\Desktop\PP1_iis21125\letter-recognition.csv",index=False)

# Normalize values for iris.csv

iris_data = pd.read_csv(r"C:\Users\UserA\Desktop\pp1\iris.csv")
norm_df2 = NormalizeValues(iris_data)
norm_df2.to_csv(r"C:\Users\UserA\Desktop\PP1_iis21125\iris.csv",index=False)

# User selects k for ENN algorithm    

k = int(input("Choose k for ENN algorithm: "))

# ENN algorithm for letter-recognition.csv

letter_recognition_data = pd.read_csv(r"C:\Users\UserA\Desktop\PP1_iis21125\letter-recognition.csv")
ENNdf = ENNalgorithm(letter_recognition_data,k)
ENNdf.to_csv(r"C:\Users\UserA\Desktop\PP1_iis21125\letter-recognitionENN.csv",index=False)
    
# ENN algorithm for iris.csv

iris_data = pd.read_csv(r"C:\Users\UserA\Desktop\PP1_iis21125\iris.csv")
ENNdf2 = ENNalgorithm(iris_data,k)
ENNdf2.to_csv(r"C:\Users\UserA\Desktop\PP1_iis21125\irisENN.csv",index=False)

# IB2 algorithm for letter-recognition.csv

letter_recognition_data = pd.read_csv(r"C:\Users\UserA\Desktop\PP1_iis21125\letter-recognition.csv")
IB2df = IB2algorithm(letter_recognition_data)
IB2df.to_csv(r"C:\Users\UserA\Desktop\PP1_iis21125\letter-recognitionIB2.csv",index=False)

# IB2 algorithm for iris.csv

iris_data = pd.read_csv(r"C:\Users\UserA\Desktop\PP1_iis21125\iris.csv")
IB2df2 = IB2algorithm(iris_data)
IB2df2.to_csv(r"C:\Users\UserA\Desktop\PP1_iis21125\irisIB2.csv",index=False)