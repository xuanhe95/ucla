    /*
#include <list>
    #include <vector>
    #include <algorithm>
    #include <iostream>
    #include <cassert>
    using namespace std;

    vector<int> destroyedOnes;

    class Movie
    {
      public:
        Movie(int r) : m_rating(r) {}
        ~Movie() { destroyedOnes.push_back(m_rating); }
        int rating() const { return m_rating; }
      private:
        int m_rating;
    };
    */
      // Remove the movies in li with a rating below 50 and destroy them.
      // It is acceptable if the order of the remaining movies is not
      // the same as in the original list.
    void removeBad(list<Movie*>& li)
    {
        for (list<Movie*>:: iterator it = li.begin(); it != li.end(); ){
            if ((*it)->rating() < 50) {
                (*it)->~Movie();
                it = li.erase(it);
            }
            else {
                it++;
            }
        }
    }
    /*
    void test()
    {
        int a[8] = { 5, 80, 60, 70, 20, 15, 90, 10 };
        list<Movie*> x;
        for (int k = 0; k < 8; k++)
            x.push_back(new Movie(a[k]));
        assert(x.size() == 8 && x.front()->rating() == 5 && x.back()->rating() == 10);
        removeBad(x);
        assert(x.size() == 4 && destroyedOnes.size() == 4);
        vector<int> v;
        for (list<Movie*>::iterator p = x.begin(); p != x.end(); p++)
        {
            Movie* mp = *p;
            v.push_back(mp->rating());
        }
          // Aside:  Since C++11, the above loop could be
          //     for (auto p = x.begin(); p != x.end(); p++)
          //     {
          //         Movie* mp = *p;
          //         v.push_back(mp->rating());
          //     }
          // or
          //     for (auto p = x.begin(); p != x.end(); p++)
          //     {
          //         auto mp = *p;
          //         v.push_back(mp->rating());
          //     }
          // or
          //     for (Movie* mp : x)
          //         v.push_back(mp->rating());
          // or
          //     for (auto mp : x)
          //         v.push_back(mp->rating());
        sort(v.begin(), v.end());
        int expect[4] = { 60, 70, 80, 90 };
        for (int k = 0; k < 4; k++)
            assert(v[k] == expect[k]);
        sort(destroyedOnes.begin(), destroyedOnes.end());
        int expectGone[4] = { 5, 10, 15, 20 };
        for (int k = 0; k < 4; k++)
            assert(destroyedOnes[k] == expectGone[k]);
        for (list<Movie*>::iterator p = x.begin(); p != x.end(); p++)
            delete *p;
    }

    int main()
    {
        test();
        cout << "Passed" << endl;
    }
    */