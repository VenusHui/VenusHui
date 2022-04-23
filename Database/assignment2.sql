SELECT ID
FROM student NATURAL LEFT OUTER JOIN takes
WHERE tot_cred = 0;

CREATE Function avg_salary (company_name VARCHAR(20))
    RETURNS INTEGER
    BEGIN
    DECLARE result INTEGER;
        SELECT AVG(salary) INTO result
        FROM works
        WHERE works.company_name = company_name
    return result;
    END
    
SELECT company_name
FROM works
WHERE avg_salary(works.company_name) > avg_salary("First Bank");

brand(name)
model(model_id,
    name)
vehicle(VIN)
option(option_id,
    specification)
customer(customer_id,
    name,
    address)
dealer(dealer_id,
    name,
    address)

has_models(name,
    model_id ,
    FOREIGN KEY name REFERENCES brand,
    FOREIGN KEY model_id REFERENCES model
)
has_vehicles(model_id,
    VIN,
    FOREIGN KEY VIN REFERENCES vehicle,
    FOREIGN KEY model_id REFERENCES model
)
available_options(model_id,
    option_id,
    FOREIGN KEY option_id REFERENCES option,
    FOREIGN KEY model_id REFERENCES model
)
has_options(VIN,
    model_id,
    option_id,
    FOREIGN KEY VIN REFERENCES vehicle,
    FOREIGN KEY (model_id, option_id) REFERENCES available options
)
has_dealer(VIN,
    dealer_id ,
    FOREIGN KEY dealer_id REFERENCES dealer,
    FOREIGN KEY VIN REFERENCES vehicle
)
owned_by(VIN,
    customer_id,
    FOREIGN KEY customer_id REFERENCES customer,
    FOREIGN KEY VIN REFERENCES vehicle
)