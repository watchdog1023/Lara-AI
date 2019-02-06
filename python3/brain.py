import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.preprocessing import LabelEncoder
from sklearn.utils import shuffle
from sklearn.model_selection import train_test_split

def read_data():
	data_sheet = ""
	df = pd.read_csv(data_sheet)
	x = df[df.columns[0:5]].values
	y = df[df.columes[5]]
	
	encoder = LabelEncoder()
	encoder.fit(y)
	y = encoder.transform(y)
	Y = one_hot_encode(y)
	print(x.shape)
	return (x, Y)

def one_hot_encode(labels):
	n_labels = len(labels)
	n_unique_labels = len(np.unique(labels))
	one_hot_encode = np.zeros((n_labels, n_unique_labels))
	one_hot_encode[np.arange(n_labels), labels] = 1
	return one_hot_encode

X, Y = read_data()

X, Y = shuffle(X, Y ,random_state = 1)

train_x, train_y, test_x, test_y = train_test_split(X, Y ,test_size=0.20, random_state = 415)

#Show Shape(Debuging)
print(train_x.shape)
print(train_y.shape)
print(test_x.shape)

#Para
learning_rate = 0.3
training_passes = 1000
cost_history = np.empty(shape=[1], dtype=float)
n_dim = X.shape[1]
print("dim = ",n_dim)
n_class = 2
model_path = ""

#net
hidden_1 = 60
hidden_2 = 60
hidden_3 = 60
hidden_4 = 60

x =tf.placeholder(tf.float32, [None, n_dim])
W = tf.Variable(tf.zeros([n_dim, n_class]))
b = tf.Variable(tf.zeros([n_class]))
y_ =tf.placeholder(tf.float, [None , n_class])
