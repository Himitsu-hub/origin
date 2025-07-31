#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <stdexcept>

struct ListNode {
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next) {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};

class List {
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head)) {
    }

    virtual ~List() {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value) {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value) {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront() {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack() {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear() {
        auto current = m_head->next;
        while (current != m_tail) {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node) {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

TEST_CASE("List operations", "[list]") {
    List list;

    SECTION("Initial state") {
        REQUIRE(list.Empty());
        REQUIRE(list.Size() == 0);
    }

    SECTION("PushBack adds elements correctly") {
        list.PushBack(1);
        REQUIRE(list.Size() == 1);
        REQUIRE_FALSE(list.Empty());

        list.PushBack(2);
        REQUIRE(list.Size() == 2);
    }

    SECTION("PushFront adds elements correctly") {
        list.PushFront(1);
        REQUIRE(list.Size() == 1);
        REQUIRE_FALSE(list.Empty());

        list.PushFront(2);
        REQUIRE(list.Size() == 2);
    }

    SECTION("PopBack removes and returns last element") {
        list.PushBack(1);
        list.PushBack(2);

        REQUIRE(list.PopBack() == 2);
        REQUIRE(list.Size() == 1);

        REQUIRE(list.PopBack() == 1);
        REQUIRE(list.Size() == 0);
        REQUIRE(list.Empty());
    }

    SECTION("PopFront removes and returns first element") {
        list.PushFront(1);
        list.PushFront(2);

        REQUIRE(list.PopFront() == 2);
        REQUIRE(list.Size() == 1);

        REQUIRE(list.PopFront() == 1);
        REQUIRE(list.Size() == 0);
        REQUIRE(list.Empty());
    }

    SECTION("PopBack on empty list throws exception") {
        REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
    }

    SECTION("PopFront on empty list throws exception") {
        REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
    }

    SECTION("Complex scenario") {
        list.PushBack(3);
        list.PushFront(2);
        list.PushBack(4);
        list.PushFront(1);

        REQUIRE(list.Size() == 4);

        REQUIRE(list.PopFront() == 1);
        REQUIRE(list.PopBack() == 4);
        REQUIRE(list.PopFront() == 2);
        REQUIRE(list.PopBack() == 3);

        REQUIRE(list.Empty());

        list.PushFront(10);
        list.PushBack(20);
        REQUIRE(list.PopBack() == 20);
        REQUIRE(list.PopFront() == 10);
    }

    SECTION("Clear works correctly") {
        list.PushBack(1);
        list.PushBack(2);
        list.PushFront(0);

        list.Clear();

        REQUIRE(list.Empty());
        REQUIRE(list.Size() == 0);

        list.PushFront(5);
        REQUIRE(list.Size() == 1);
        REQUIRE(list.PopFront() == 5);
    }
}