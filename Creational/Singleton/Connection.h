#include <string>
#include <mutex>

class Connection
{
public:
    static Connection *getInstance()
    {
        if (nullptr == mConnection)
        {
            std::lock_guard(mMutex);
            if (nullptr == mConnection)
            {
                return new Connection();
            }
        }
        return mConnection;
    }

private:
    Connection() {}

    Connection(const Connection &) = delete;

    std::string username;

    static Connection *mConnection;

    static std::mutex mMutex;
};