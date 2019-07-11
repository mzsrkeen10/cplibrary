/*
    n個からk個とった順列(nPk)の列挙

    Usage:
        beginに先頭要素へのイテレータ，
        middleにk番目(0-indexed)の要素へのイテレータ，
        lastに最後尾要素の次を指すイテレータを与える

    Verified:
        AOJ 0546 Lining up the cards
*/

template <class BidirectionalIterator>
inline constexpr bool next_partial_permutation(BidirectionalIterator first,
                                               BidirectionalIterator middle,
                                               BidirectionalIterator last) {
    std::reverse(middle, last);
    return std::next_permutation(first, last);
}
