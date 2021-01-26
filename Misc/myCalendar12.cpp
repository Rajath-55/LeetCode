class MyCalendarTwo
{
public:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> booked;

    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        for (auto x : booked)
        {
            if (start < x.second && x.first < end)
                return false;
        }
        for (auto x : bookings)
        {
            if (start < x.second && x.first < end)
            {
                booked.push_back(make_pair(max(start, x.first), min(end, x.second)));
            }
        }

        bookings.push_back(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */