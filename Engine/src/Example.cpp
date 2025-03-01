#include "Example.hpp"

namespace Stronk {

    Example::Example() : value("Hello, world!") {}
    auto Example::Get() -> std::string {
        return value;
    };
}
