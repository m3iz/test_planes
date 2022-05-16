// Картинка с примером
// https://ibb.co/S05pYNc
#include <map>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <iostream>
using namespace std;


//std::pair<>

vector < pair<string, string> > getFlightsList()
{
    vector <pair<string,string>> result;
    result.push_back( { "Moscow", "Berlin" });
    result.push_back({ "Berlin", "Vena" });
    result.push_back({ "Moscow", "Berlin" });
    result.push_back({ "Moscow", "Berlin" });
    result.push_back({ "Berlin", "Moscow" }); 
    result.push_back({ "Moscow", "Berlin" });
    result.push_back({ "Vena", "Berlin" });
    result.push_back({ "Moscow", "Vena" });
    result.push_back({ "London", "Vena" });

    // Тут что то делается и возвращается список перелетов компании
    /*
    Москва - Берлин
    Берлин - Вена
    Москва - Берлин
    Москва - Берлин
    Берлин - Москва ///
    Москва - Берлин
    Вена   - Берлин
    Москва - Вена
    Лондон - Вена
    ...
    */
    return result;

}

unordered_set <string> getCitiesList(vector < pair<string, string> > flights)
{
    unordered_set <string> res;

    for (auto a : flights) {
        res.insert(a.first);
        res.insert(a.second);
    }
    return res;

}

vector < pair<string, string> > getUniqueFlights(vector < pair<string, string> > flights)
{
    vector < pair<string, string> > result;
    set < pair <string, string > > myset;
    for (auto a : flights) {
        pair<string, string>temp = make_pair(a.second, a.first);
        if ((myset.count(temp) != 1)&&(myset.count(a) !=1))
            result.push_back(a);
            myset.insert(a);
    }
    return result;
}
struct foo
{
    string p1;
    string p2;
};
pair<string, string>test;


int main()
{
 
    vector < pair<string, string> > flights = getFlightsList();

    unordered_set <string> cities = getCitiesList(flights);

    vector < pair<string, string> > uniqueFlights = getUniqueFlights(flights);
    for (auto a : uniqueFlights) {
        cout << a.first << " " << a.second << endl;
    }
    return 0;
}
