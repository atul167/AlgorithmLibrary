// https://www.geeksforgeeks.org/insertion-sort/

/*
Best time = O(n)
Worst Time = O(n^2)
*/


/*
Algorithm 
To sort an array of size n in ascending order: 
1: Iterate from arr[1] to arr[n] over the array. 
2: Compare the current element (key) to its predecessor. 
3: If the key element is smaller than its predecessor, compare it to the elements before. 
   Move the greater elements one position up to make space for the swapped element.
*/

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j = j - 1;
        }
        arr[j] = key;
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";  
}












void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if(arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            } else {
                break;
            }
        }
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
