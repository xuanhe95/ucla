/*
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
      // Remove the movies in v with a rating below 50 and destroy them.
      // It is acceptable if the order of the remaining movies is not
      // the same as in the original vector.
    void removeBad(vector<Movie*>& v)
    {
        for (vector<Movie*>:: iterator it = v.begin(); it != v.end(); ){
            if ((*it)->rating() < 50) {
                (*it)->~Movie();
                it = v.erase(it);
            }
            else {
                it++;
            }
        }
    }
    /*
    void test()
    {
        int a[8] = { 20, 80, 30, 70, 85, 15, 90, 10 };
        vector<Movie*> x;
        for (int k = 0; k < 8; k++)
            x.push_back(new Movie(a[k]));
        assert(x.size() == 8 && x.front()->rating() == 20 && x.back()->rating() == 10);
        removeBad(x);
        assert(x.size() == 4 && destroyedOnes.size() == 4);
        vector<int> v;
        for (int k = 0; k < 4; k++)
            v.push_back(x[k]->rating());
        sort(v.begin(), v.end());
        int expect[4] = { 70, 80, 85, 90 };
        for (int k = 0; k < 4; k++)
            assert(v[k] == expect[k]);
        sort(destroyedOnes.begin(), destroyedOnes.end());
        int expectGone[4] = { 10, 15, 20, 30 };
        for (int k = 0; k < 4; k++)
            assert(destroyedOnes[k] == expectGone[k]);
        for (vector<Movie*>::iterator p = x.begin(); p != x.end(); p++)
            delete *p;
    }

    int main()
    {
        test();
        cout << "Passed" << endl;
    }
    */