#include <iostream>

unsigned int ackermann(unsigned int m, unsigned int n) {
	if (m == 0) {
		return n + 1;
	}
	if (n == 0) {
		return ackermann(m - 1, 1);		
	}
	return ackermann(m - 1, ackermann(m, n - 1));
}

int main() {
	int arr1[] = {1,2,3,4};
	int arr2[] = {0,1,2,3,4};
	for (unsigned int m = 0; m < (sizeof(arr1)/sizeof(*arr1)); m++) {
		for (unsigned int n = 0; n < (sizeof(arr2)/sizeof(*arr2)); n++) {
			if(arr1[m]==4 && arr2[n]==2)
			{
				break;
			}
			std::cout << "A(" << arr1[m] << ", " << arr2[n] << ") = " << ackermann(arr1[m], arr2[n]) << "\n";
		}
	}
}