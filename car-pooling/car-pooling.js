var carPooling = function(trips, capacity) {
    let dict = {}
    let currentPassengers = 0 
    
    for (let trip of trips) {
        const pickup = trip[1]
        const dropoff = trip[2]
        const passengers = trip[0]
        
        
        let pickupArray = dict[pickup]
        if (!pickupArray) {
            dict[pickup] = [ passengers ]
        } else {
            pickupArray.push(passengers)
            dict[pickup] = pickupArray
        }
        
        let dropoffArray = dict[dropoff]
        if (!dropoffArray) {
            dict[dropoff] = [ -passengers ]
        } else {
            dropoffArray.push(-passengers)
            dict[dropoff] = dropoffArray
        }
    }
    
    for (let i=0; i<= 1000; i++) {
        const info = dict[i]
        if (!info) {
            continue
        }
		// At each point, we must **drop of the passengers first**, then we load the passenger, otherwise the answer might be wrong.
        for (let passenger of info) {
            if (passenger < 0) {
                currentPassengers = currentPassengers + passenger
            }
        }
        for (let passenger of info) {
            if (passenger > 0) {
                currentPassengers = currentPassengers + passenger
            }
            if (currentPassengers > capacity) {
                return false
            }
        }
    }
    
    return true 
};