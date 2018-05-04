#ifndef NOCOPYABLE_H
#define NOCOPYABLE_H

namespace myPool {

class nocopyable {
public:
    nocopyable() = default;
    ~nocopyable() = default;
private:
    nocopyable(const nocopyable& x) = delete;
    nocopyable& operator=(const nocopyable&x) = delete;
};

}

#endif // NOCOPYABLE_H

