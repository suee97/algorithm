#include <bits/stdc++.h>
using namespace std;
int n, maxN;
string s1 = "\"����Լ��� ������?\"\n";
string s2 = "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
string s3 = "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
string s4 = "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";

string s5 = "��� �亯�Ͽ���.\n";

string s6 = "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";

void func(int n) {
    if (n == 0) return;
    string bar = "";
    for (int i = maxN-1; i >= n; i--) {
        bar += "____";
    }
    cout << bar + s1;
    if (n == 1) {
        cout << bar + s6;
    } else {
        cout << bar + s2;
        cout << bar + s3;
        cout << bar + s4;
    }

    func(n-1);
    cout << bar + s5;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    maxN = n+1;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    func(n+1);
}