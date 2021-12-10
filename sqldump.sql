create view samePrice as
    SELECT cu.cust_id, cu.cust_name, cu.address, it.item_name, it.price, sa.bill_no 
    FROM customer cu, item it, sale sa
    GROUP BY it.price
    HAVING COUNT(price) > 1
    ON cu.cust_id = sa.cust_id;