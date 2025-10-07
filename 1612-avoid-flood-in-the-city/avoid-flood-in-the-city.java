class Solution {
    public int[] avoidFlood(int[] trajectory) {
        int sz = trajectory.length;
        int[] result_path = new int[sz];
        java.util.Map<Integer, Integer> last_storm_day = new java.util.HashMap<>();
        java.util.TreeSet<Integer> clear_sky_days = new java.util.TreeSet<>();

        for (int day_idx = 0; day_idx < sz; day_idx++) {
            int celestial_body = trajectory[day_idx];
            if (celestial_body > 0) {
                result_path[day_idx] = -1;
                if (last_storm_day.containsKey(celestial_body)) {
                    int prev_storm_day = last_storm_day.get(celestial_body);
                    Integer next_dry_day = clear_sky_days.higher(prev_storm_day);
                    if (next_dry_day == null) return new int[0];
                    result_path[next_dry_day] = celestial_body;
                    clear_sky_days.remove(next_dry_day);
                }
                last_storm_day.put(celestial_body, day_idx);
            } else {
                clear_sky_days.add(day_idx);
            }
        }

        for (int dry_day : clear_sky_days) {
            result_path[dry_day] = 1;
        }

        return result_path;
    }
}