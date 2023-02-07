from sklearn import datasets
import seaborn as sns
dir(datasets)

# print("Analog ED analysis")
iris =  datasets.load_iris()
# dir(iris)
# print(iris.DESCR)
# print(iris.data)
# print(iris.data.shape)
# print(iris.feature_names)
# print(iris.target)
# print(iris.target_names)
# print(iris)

print("Graphical ED analysis")
# dir(sns)
iris_data = sns.load_dataset('iris')
# print(iris_data)
correlation = iris_data.corr() 
# print(correlation) #features correlation
sns.heatmap(correlation,cmap='winter',annot=True)

from pycaret.datasets import get_data
from pycaret.cassification import *
a = get_data('idex')
print(a)
iris = get_data('iris')
a = setup(iris,tergert="species")
compare_models()





