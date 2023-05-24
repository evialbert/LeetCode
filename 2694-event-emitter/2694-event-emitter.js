class EventEmitter {

    constructor() {
        this.subscribers = new Map();
    }

    subscribe(event, cb) {
        const eventCallbacks = this.getEventCallbacks(event);

        eventCallbacks.push(cb);
        this.subscribers.set(event, eventCallbacks);

        return {
            unsubscribe: () => {
                this.subscribers.set(event, eventCallbacks.filter(_cb => _cb !== cb));
            }
        };
    }

    emit(event, args = []) {
        const eventCallbacks = this.getEventCallbacks(event);
        const res = [];

        for (const cb of eventCallbacks) {
            res.push(cb.apply(null, args));
        }

        return res;
    }

    getEventCallbacks(event) {
        return this.subscribers.get(event) ?? [];
    }
}
/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */