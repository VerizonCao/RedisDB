#ifndef REDIS_ITERATORH
#define REDIS_ITERATORH
namespace RedisDataStructure
{
    template <typename T>
    class RedisBidirectionalIterator : public std::iterator<std::bidirectional_iterator_tag, T, ptrdiff_t, T *, T &>
    {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;

    public:
        RedisBidirectionalIterator(T *ptr) : mPtr(ptr) {}
        RedisBidirectionalIterator(const RedisBidirectionalIterator<T> &other) { mPtr = other.mPtr; };
        RedisBidirectionalIterator<T> &operator=(const RedisBidirectionalIterator<T> &other) { mPtr = other.mPtr; };
        //RedisBidirectionalIterator(RedisBidirectionalIterator<T> &&other) = delete;
        //RedisBidirectionalIterator<T> &operator = (RedisBidirectionalIterator<T> &&other) = delete;
        ~RedisBidirectionalIterator() {}

        T &operator*() { return *mPtr; }
        const T &operator*() const { return *mPtr; }
        T *operator->() { return mPtr; }
        T *getPtr() const { return mPtr; }
        const T *getConstPtr() const { return mPtr; }

        RedisBidirectionalIterator<T> &operator++()
        {
            mPtr = mPtr->next();
            return (*this);
        }
        RedisBidirectionalIterator<T> &operator--()
        {
            mPtr = mPtr->prev();
            return (*this);
        }
        RedisBidirectionalIterator<T> operator++(int)
        {
            auto temp(*this);
            mPtr = mPtr->next();
            return temp;
        }
        RedisBidirectionalIterator<T> operator--(int)
        {
            auto temp(*this);
            mPtr = mPtr->prev();
            return temp;
        }
        bool operator==(const RedisBidirectionalIterator<T> &rawIterator) const { return (mPtr == rawIterator.getConstPtr()); }
        bool operator!=(const RedisBidirectionalIterator<T> &rawIterator) const { return (mPtr != rawIterator.getConstPtr()); }

    protected:
        T *mPtr;
    };

    template <typename T>
    class RedisBidirectionalReverseIterator : public RedisBidirectionalIterator<T>
    {
    public:
        RedisBidirectionalReverseIterator<T>(T *ptr) : RedisBidirectionalIterator(ptr) {}
        RedisBidirectionalReverseIterator<T> &operator++()
        {
            mPtr = mPtr->prev();
            return (*this);
        }
        RedisBidirectionalReverseIterator<T> &operator--()
        {
            mPtr = mPtr->next();
            return (*this);
        }
        RedisBidirectionalReverseIterator<T> operator++(int)
        {
            auto temp(*this);
            mPtr = mPtr->prev();
            return temp;
        }
        RedisBidirectionalReverseIterator<T> operator--(int)
        {
            auto temp(*this);
            mPtr = mPtr->next();
            return temp;
        }
    };
}; // namespace RedisDataStructure
#endif