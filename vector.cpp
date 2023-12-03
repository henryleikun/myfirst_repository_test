//vector��С  ��ε��÷�������Ԫ��  ����Ԫ��  ɾ��Ԫ��

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


int main() {
    //��С
    int arr[]{ 1,2,3,4,5 };
    int i;
    vector<int> v1(arr, arr + 5);

    for (i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }

    cout << endl;

    cout << "vi.size:" << v1.size() << endl;//v1.size()����Ԫ�ظ���

    if (!v1.empty())
        cout << "v1 is not empty!" << endl;//v1.empty()�ж������Ƿ�Ϊ�� ��1��0

    v1.resize(6);//v1.resize(num)��Ĭ��ֵ������� ��numС��ԭ��������С ��ɾ��ԭ���Ķ����Ԫ��
    //������ԭ���Ĵ�С  ����Ĭ��ֵ �������
    cout << "v1.resize(6)���Ԫ��:";

    for (i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    v1.resize(8, 100);//v1.resize(num,elem) ����һ����ͬ���� ָ����elem�����Ԫ��

    for (i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    //����(���÷��� ���ǵ�����)
    vector<int> v2(arr, arr + 5);

    cout << "v2�����ĵ�����Ԫ�أ�[]���ʣ���";
    cout << v2[2] << endl;//[]���� []����ģ��vector������

    cout << "v2�����ĵ�����Ԫ�أ�at()���ʣ�:";
    cout << v2.at(2) << endl;//����һ���������� ������������Խ��ʱ�����쳣��ʾ  ����һ�������� ���ڲ��Ҵ���ʱ�����ܴ�

    //����  ��ĩβ����push_back() ��ĩβɾ��pop_back() �Ͷ������insert()
    vector<int> v3 = v2;

    v3.insert(v3.begin(), 0);//insert(pos,elem)��pos(ָ�룬����������)λ�ò���һ�� elem  ���������ݵ�λ��
    cout << "��v3�ĵ�һ��Ԫ�ش� ����һ��0��";

    for (i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    cout << endl;

    v3.insert(v3.begin(), 3, 7);//insert(pos,n,elem)��posλ�ò���n��elemԪ��  �޷���ֵ

    cout << "��v3�ĵ�һ��Ԫ�س����� 3��7��";
    for (i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    cout << endl;

    vector<int> vtemp(3, 9);

    cout << "v3���ڵ�һ��Ԫ���ϲ���3��9��";

    v3.insert(v3.begin(), vtemp.begin(), vtemp.end());//insert(pos,beg,end)��posλ�ò���[beg,end)�ϵ�Ԫ��  �޷���ֵ
    for (i = 0; i < v3.size(); i++) {
          cout << v3[i] << " ";
    }
    cout << endl;

    v3.push_back(300);//������β������300

    cout << "��v3��β������300��";

    for (i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    cout << endl;


    v3.pop_back();

    cout << "ɾ��v3�����һ��Ԫ�أ�";

    for (i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    cout << endl;


    return 0;
}
