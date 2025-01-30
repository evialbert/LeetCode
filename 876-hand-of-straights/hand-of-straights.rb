# @param {Integer[]} hand
# @param {Integer} group_size
# @return {Boolean}
def is_n_straight_hand(hand, group_size)
    if (hand.size % group_size != 0)
        return false
    end

    hand.sort!
    while hand.size > 0
        count = 1
        last_num = hand.shift
        while count < group_size
            next_num = last_num + 1
            index = hand.bsearch_index{|n| next_num <=> n}
            if !index
                return false
            else
                hand.delete_at(index)
            end
            last_num = next_num
            count = count + 1
        end
    end

    return true
end