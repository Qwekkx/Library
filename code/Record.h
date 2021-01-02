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
    cout << "name: " << name
         << "data: " << date
         << "book: " << book->name
         << "duration: " << duration
         << endl;
}