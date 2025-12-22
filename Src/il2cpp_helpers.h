#pragma once

namespace il2cpp
{
    std::string GetString(const Il2CppString* s);
    //specific to PlayerOptionsData.saveDate if i ever need it...
    std::string ReadableSaveDateString(const Il2CppString* s);

    template<typename T, typename F>
    inline void List_ForEach(const Il2CppList<T>* list, F&& fn)
    {
        if (!list || !list->items)
            return;
        const auto* items = list->items;
        const int size = list->size;
        const int cap = static_cast<int>(items->max_length);
        const int safeSize = (size < cap) ? size : cap;
        for (int i = 0; i < safeSize; ++i)
            fn(items->m_Items[i], i);
    }

    template<typename TKey, typename TValue, typename F>
    inline void Dictionary_ForEach(const Il2CppDictionary<TKey, TValue>* dict, F&& fn)
    {
        if (!dict || !dict->entries)
            return;
        const auto* entries = dict->entries;
        const int cap = static_cast<int>(entries->max_length);
        for (int i = 0; i < cap; ++i)
        {
            const auto& e = entries->m_Items[i];
            if (e.hashCode < 0)
                continue;
            fn(e.key, e.value, i);
        }
    }
    template<typename T, typename TKey, typename TValue>
    inline T Dictionary_TryGet(const Il2CppDictionary<TKey, TValue>* dict, const TKey& needle)
    {
        if (!dict || !dict->entries)
            return {};
        const auto* entries = dict->entries;
        const int cap = static_cast<int>(entries->max_length);
        for (int i = 0; i < cap; ++i)
        {
            const auto& e = entries->m_Items[i];
            if (e.hashCode < 0)
                continue;
            if (e.key == needle)
                return static_cast<T>(e.value);
        }
        return {};
    }
}