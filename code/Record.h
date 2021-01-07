class Record
{
public:
    string name;
    string date;
    Book *book;
    long long duration;
    void printInfo();
};

void Record::printInfo()
{
    cout << " book: " << name
         << " date: " << date
         << " duration: " << duration
         << endl;
}