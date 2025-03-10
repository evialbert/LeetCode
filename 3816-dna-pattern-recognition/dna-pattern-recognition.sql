-- Write your PostgreSQL query statement below
select * ,
(case when dna_sequence ~ '^ATG' then 1 else 0 end) as has_start,
(case when dna_sequence ~ 'TAA$' OR dna_sequence ~ 'TAG$' OR dna_sequence ~ 'TGA$' then 1 else 0 end) as has_stop,
(case when dna_sequence ~ 'ATAT' then 1 else 0 end) as has_atat,
(case when dna_sequence ~ 'GGG' then 1 else 0 end) as has_ggg
from samples;