# Write your MySQL query statement below


with t as (
    select b.customer_id, b.order_date, b.customer_pref_delivery_date, b.rnk from (
        select *, rank() over (partition by customer_id order by order_date) as rnk
        from Delivery
    ) as b
    where b.rnk = 1
)




select round((count(*) / (select count(*) from t) * 100), 2) as immediate_percentage from t
where t.order_date = t.customer_pref_delivery_date;

-- select 
-- count(customer_id case )

-- from Delivery