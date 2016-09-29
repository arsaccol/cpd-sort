import math

def parent(childIndex):
	if childIndex == 0:
		return 0
	return math.floor((childIndex - 1) / 2)


def leftChild(parentIndex):
	return parentIndex * 2 + 1
	
	
def rightChild(parentIndex):
	return parentIndex * 2 + 2


def max_heapify(array, index):
# Diagnostics
	print("\tRunning max_heapify", array)

	left = leftChild(index)
	right = rightChild(index)

	greatest = index 

	if left < len(array) and array[left] > greatest: # Disregard if out of bounds
		greatest = left
	if right < len(array) and array[right] > greatest: # Disregard if out of bounds
		greatest = right

	if greatest != index:
		array[greatest], array[index] = array[index], array[greatest]
		max_heapify(array, greatest)
	print("Max heapified: ", array)


def build_max_heap(array):
	print("Building heap with array: ", array)
	# Last branch is the parent of the last leaf
	for i in range(math.floor(len(array) / 2), 0, -1):
		print("Heapifying array[" + str(i) + "] (" + str(array[i]) + ")")
		max_heapify(array, i)

def heap_diagnostics(array):
	print("\n")
	print("Heap diagnostics of array: ", array)
	for i in range(0, len(array)-1):
		print("Parent of " + str(array[i]) + " (array["  + str(i) + "]) is " + str(array[parent(i)]))
		if leftChild(i) < len(array):
			print("Left child of " + str(array[i]) + " (array[" + str(i) + "]) is " + str(array[leftChild(i)]))
		if rightChild(i) < len(array):
			print("Right child of " + str(array[i]) + " (array[" + str(i) + "]) is " + str(array[rightChild(i)]))
		print("\n")

if __name__ == '__main__':
	array = [0, 1, 3, 5, 9, 8, 4, 6]
	x_array = [256, 32, 64, 512] 
	print(array)
	
	build_max_heap(array)
	print(array)

	heap_diagnostics(array)

	max_heapify(array, -1)
	print(array)

#	build_max_heap(x_array)
#	print(x_array)




