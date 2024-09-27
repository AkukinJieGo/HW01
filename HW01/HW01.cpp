// HW01.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>

using namespace std;

// 解析多項式字串並轉換為map
map<int, int> parsePolynomial(const string& input) {
    map<int, int> polynomial;   // 儲存次方與係數
    istringstream iss(input);   // 解析使用者的輸入
    int coefficient, exponent;  // 存儲目前的係數與次方
    // 讀取輸入的係數和次方
    while (iss >> coefficient >> exponent) {  
        polynomial[exponent] += coefficient;  // 次方相同，係數相加
    }
	return polynomial;  // 回傳多項式map
}

// 將多項式map轉換為字串
string polynomialToString(const map<int, int>& polynomial) {
    ostringstream oss;  
    bool first = true;  // 避免+出現在第一項
    // 從最高次方開始輸出
    for (auto it = polynomial.rbegin(); it != polynomial.rend(); ++it) { 
		if (it->second == 0) continue;  // 係數為0時不輸出
		if (!first && it->second > 0) oss << "+"; // 略過第一項，係數為正時加上"+"
		// 如果次方數為0則只顯示常數項，否則顯示"x^次方"
        if (it->first == 0) {
            oss << it->second;
        }
        else {
            oss << it->second << "x^" << it->first;
        }
        first = false;  // 已經處理完第一項
    }
	return oss.str();   // 回傳多項式字串
}

// 多項式相加
map<int, int> addPolynomials(const map<int, int>& p1, const map<int, int>& p2) {
	map<int, int> result = p1;  // 複製p1到result
	// 將p2的項加到result中
    for (const auto& term : p2) {
		result[term.first] += term.second;  // 次方相同，係數相加
    }
	return result;  // 回傳相加結果
}

// 多項式相乘
map<int, int> multiplyPolynomials(const map<int, int>& p1, const map<int, int>& p2) {
	map<int, int> result;  // 儲存相乘結果
    // 將兩個多項式的每一項進行相乘
    for (const auto& term1 : p1) {
        for (const auto& term2 : p2) {
			result[term1.first + term2.first] += term1.second * term2.second;  // 次方相加，係數相乘
        }
    }
	return result;  // 回傳相乘結果
}

int main() {
	string input1, input2;  // 儲存使用者輸入的多項式

    cout << "請輸入第一個多項式 (格式: 係數 次方 係數 次方 ...): ";  // 輸入第一個多項式
    getline(cin, input1);
    cout << "請輸入第二個多項式 (格式: 係數 次方 係數 次方 ...): ";  // 輸入第二個多項式
    getline(cin, input2);

    // 解析輸入的數據並轉換為多項式map
    auto poly1 = parsePolynomial(input1);
    auto poly2 = parsePolynomial(input2);

	// 輸出兩個多項式
    cout << "多項式 1: " << polynomialToString(poly1) << endl;
    cout << "多項式 2: " << polynomialToString(poly2) << endl;

    auto sum = addPolynomials(poly1, poly2);  // 兩多項式相加
	auto product = multiplyPolynomials(poly1, poly2);  // 兩多項式相乘

	cout << "相加結果: " << polynomialToString(sum) << endl;  // 輸出相加結果
	cout << "相乘結果: " << polynomialToString(product) << endl;  // 輸出相乘結果

    return 0;
}



// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
