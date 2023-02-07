import numpy as np
import matplotlib.pyplot as plt
import matplotlib.style as stl
from collections import Counter
stl.use('fivethirtyeight')

dataset = {
    'k': [[210,90],[201,95],[202,97],[203,98],[205,96],[204,99],[207,94]],
    'r': [[170,80],[168,82],[175,83],[179,84],[180,79],[173,82],[176,85]]
}

def scatter_plot(dataset,new_sample):
    for group in dataset:
        for feature in dataset[group]:
            plt.scatter(feature[0], feature[1], s = 100, color = group)
    plt.scatter(new_sample[0], new_sample[1], color = 'b',marker='*')
    plt.show()
    
def K_NN(dataset,predict,k):
    distance = []
    for group in dataset:
        for feature in dataset[group]:
            eucladian_distance = np.linalg.norm(np.array(feature)-np.array(predict))
            distance.append([eucladian_distance,group])
    
    votes = [i[1] for i in sorted(distance)[:k]]
    votes_result = Counter(votes).most_common(1)[0][0]
    return votes_result

while True:
    new_input = input("Enter a new sample [weight,height]= ").split(",")
    
    new_sample = []
    new_sample.append(int(new_input[0]))
    new_sample.append(int(new_input[1]))
    
    if new_sample == [0,0]:
        break
    else:
        print(new_sample)
        scatter_plot(dataset, new_sample)
        result = K_NN(dataset, new_sample, 3)
        print("Result",result)
        if result == 'k':
            print('Wristler')
        else:
            print('Swimmer')