#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include<ctime>
#include "SequenceST.h"
#include "FileOps.h"
#include"BST.h"

using namespace std;

//void shuffle(int arr[], int n) {
//
//	srand(time(NULL));
//	for (int i = n - 1; i >= 0; i--) {
//		int x = rand() % (i + 1);
//		swap(arr[i], arr[x]);
//	}
//}
//int main() {
//
//	srand(time(NULL));
//	BST<int, int> bst = BST<int, int>();
//
//	const int n = 1000;
//	for (int i = 0; i < n; i++) {
//		int key = rand() % n;
//		// 为了后续测试方便,这里value值取和key值一样
//		int value = key;
//		//cout<<key<<" ";
//		bst.insert(key, value);
//	}
//
//	// test remove
//	// remove elements in random order
//	int order[n];
//	for (int i = 0; i < n; i++)
//		order[i] = i;
//	shuffle(order, n);
//
//	for (int i = 0; i < n; i++)
//		if (bst.contain(order[i])) {
//			bst.remove(order[i]);
//			cout << "After remove " << order[i] << " size = " << bst.size() << endl;
//		}
//	system("pause");
//	return 0;
//}

//testSearch二叉搜索树的局限性
int main() {

	string filename = "communist.txt";
	vector<string> words;
	if (FileOps::readFile(filename, words)) {

		cout << "There are totally " << words.size() << " words in " << filename << endl;

		cout << endl;


		// test BST
		time_t startTime = clock();
		BST<string, int> *bst = new BST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int *res = (*bst).search(*iter);
			if (res == NULL)
				(*bst).insert(*iter, 1);
			else
				(*res)++;
		}

		cout << "'unite' : " << *(*bst).search("unite") << endl;//统计unite单词的词频
		time_t endTime = clock();
		cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

		cout << endl;

		delete bst;


		// test SST
		startTime = clock();
		SequenceST<string, int> *sst = new SequenceST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int *res = (*sst).search(*iter);
			if (res == NULL)
				(*sst).insert(*iter, 1);
			else
				(*res)++;
		}

		cout << "'unite' : " << *(*sst).search("unite") << endl;

		endTime = clock();
		cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

		cout << endl;

		delete sst;


		// test BST2，退化成了链表
		startTime = clock();
		BST<string, int> *bst2 = new BST<string, int>();

		sort(words.begin(), words.end());

		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int *res = (*bst2).search(*iter);
			if (res == NULL)
				(*bst2).insert(*iter, 1);
			else
				(*res)++;
		}

		cout << "'unite' : " << *(*bst2).search("unite") << endl;
		endTime = clock();
		cout << "BST2 , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

		cout << endl;

		delete bst2;

	}
	system("pause");
	return 0;
}

//int main()
//{
//
//	system("pause");
//	return 0;
//}