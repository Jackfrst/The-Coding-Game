from turtle import color
import numpy as np 
import matplotlib as mtp 
from matplotlib import pyplot as plt 
from matplotlib import style
from collections import Counter
style.use('fivethirtyeight')

dataset = {
	'k':[[210,90],[201,95],[202,97],[203,98],[205,96],[204,99],[207,94]],
	'r':[[170,80],[168,82],[175,83],[179,84],[180,79],[173,82],[176,85]],
	'c':[[150,60],[158,62],[155,63],[159,64],[140,59],[143,52],[156,55]],
	'm':[[130,40],[138,42],[135,33],[139,34],[130,39],[133,42],[136,35]],
}

def scatter_plot(new_sample):
	for i in dataset:
		for j in dataset[i]:
			plt.scatter(j[0],j[1],s=100,color=i)

	plt.scatter(new_sample[0],new_sample[1],color='b',marker = '*')		
	plt.show()

def K_NN(data,predict,k):
	distances =[]
	for group in data:
		for features in data[group]:
			euclidian_distance = np.linalg.norm(np.array(features)-np.array(predict))	
			distances.append([euclidian_distance,group])		
	votes = [i[1]for i in sorted(distances)[:k]]
	vote_result = Counter(votes).most_common(1)[0][0]
	return vote_result

while True:
	new_arr = input('Enter a new sample [height,weight]:').split(',') 
	new_sample = []
	new_sample.append(int(new_arr[0]))
	new_sample.append(int(new_arr[1]))

	if new_sample==[0,0]:
		break
	else:
		print(new_sample)
		scatter_plot(new_sample)
		result = K_NN(dataset,new_sample,5)
		if result == 'k':
			print('Wrestler')
		elif result == 'c':
			print('Runner')
		elif result == 'm':
			print('Swimmer')		
		else:
			print('Criketer')		



