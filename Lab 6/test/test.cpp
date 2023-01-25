#include <igloo/igloo.h>
#include <Array.h>
#include <SortedArray.h>

using namespace igloo;

int main() {

Context(SortedA){
	Spec(SortUnsortedA){
	SortedArr expected;
	expected.append(26);
	expected.append(36);
	expected.append(46);
	expected.append(56);
	expected.append(76);
	expected.append(86);
	expected.append(96);
	expected.append(106);
	SortedArr actual;
	actual.insert(76);
	actual.insert(56);
	actual.insert(26);
	actual.insert(36);
	actual.insert(46);
	actual.insert(86);
	actual.insert(96);
	actual.insert(106);


Assert::That(actual,Equals(expected));

	}

};


Context(SortedB){
	Spec(SortUnsortedB){
	SortedArr expected;
	expected.append(1);
	expected.append(2);
	expected.append(3);
	expected.append(4);
	expected.append(5);
	expected.append(6);
	expected.append(7);
	expected.append(8);
	SortedArr actual;
	actual.insert(7);
	actual.insert(1);
	actual.insert(6);
	actual.insert(5);
	actual.insert(4);
	actual.insert(3);
	actual.insert(2);
	actual.insert(8);


Assert::That(actual,Equals(expected));

	}

};
Context(SortedC){
	Spec(SortUnsortedC){
	SortedArr expected;
	expected.append(1);
	expected.append(12);
	expected.append(31);
	expected.append(51);
	expected.append(90);
	expected.append(150);
	expected.append(400);
	expected.append(3000);
	SortedArr actual;
	actual.insert(90);
	actual.insert(150);
	actual.insert(1);
	actual.insert(51);
	actual.insert(400);
	actual.insert(3000);
	actual.insert(12);
	actual.insert(31);


Assert::That(actual,Equals(expected));

	}
};


Context(SortedD){
	Spec(SortUnsortedD){
	SortedArr expected;
	expected.append(70);
	expected.append(89);
	expected.append(93);
	expected.append(104);
	expected.append(150);
	expected.append(200);
	expected.append(230);
	expected.append(231);
	SortedArr actual;
	actual.insert(93);
	actual.insert(150);
	actual.insert(104);
	actual.insert(200);
	actual.insert(231);
	actual.insert(230);
	actual.insert(70);
	actual.insert(89);


Assert::That(actual,Equals(expected));
	}
};
	return TestRunner::RunAllTests();
}
