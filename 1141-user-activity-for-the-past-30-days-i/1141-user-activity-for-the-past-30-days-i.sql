# Write your MySQL query statement below
# select A1.activity_date as day, count(distinct(A1.user_id)) as active_users
# from Activity A1, Activity A2
# where TO_DAYS(A1.activity_date) - TO_DAYS(2019-07-27) <= 30
# group by A1.activity_date

select activity_date as day, count(distinct(user_id)) as active_users
from Activity
where TO_DAYS('2019-07-27') - TO_DAYS(activity_date) < 30 and TO_DAYS('2019-07-27') - TO_DAYS(activity_date) > 0
group by activity_date