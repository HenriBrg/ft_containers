
#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    // Déclare une map à clefs multiples :
    typedef multimap<int, char *> Int2String;
    Int2String m;
    // Remplit la map :
    m.insert(Int2String::value_type(2, "Deux"));
    m.insert(Int2String::value_type(4, "Quatre"));
    // Recherche un élément de clef 4 et l'affiche :
    Int2String::iterator i = m.find(4);
    cout << i->first << " : " << i->second << endl;
    // Recherche le premier élément de clef 3 :
    i = m.lower_bound(3);
    // Affiche tous les éléments dont la clef vaut 3 :
    while (i != m.upper_bound(3))
    {
        cout << i->first << " : " << i->second << endl;
        ++i;
    }
    // Effectue la même opération, mais de manière plus efficace
    // (upper_bound n'est pas appelée à chaque itération) :
    pair<Int2String::iterator, Int2String::iterator> p = m.equal_range(3);
    for (i = p.first; i != p.second; ++i)
    {
        cout << i->first << " : " << i->second << endl;
    }
    return 0;
}
