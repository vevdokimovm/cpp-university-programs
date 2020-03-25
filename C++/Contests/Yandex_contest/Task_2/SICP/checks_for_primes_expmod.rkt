#lang racket
(define (square x) (* x x))

(define (next test-divisior)
  (if (= test-divisior 2) 3 (+ test-divisior 2)))

(define (even? n) (= (remainder n 2) 0))

(define (smallest-divisior n)
  (find-divisior n 2))
  
(define (find-divisior n test-divisior)
  (cond ((> (square test-divisior) n) n)
       ((= (remainder n test-divisior) 0) test-divisior)
       (else (find-divisior n (next test-divisior)))))

(define (prime? n)
  (= (smallest-divisior n) n))

(define (timed-prime-test n)
  (start-prime-test n (current-milliseconds)))

(define (start-prime-test n start-time)
  (when (fast-prime? n)
      (report-prime n (- (current-milliseconds) start-time))))

(define (fast-prime? n times)
  (cond ((= times 0) #t)
        ((fermat-test n) (fast-prime? n (- times 1)))
        (else #f)))

(define (fermat-test n)
  (define (try-it a)
    (= (expmod a n n) a))
  (try-it (+ 1 (random (- n 1)))))

(define (expmod base exp m)
  (cond ((= exp 0) 1)
        ((even? exp)
         (remainder (square (expmod base (/ exp 2) m)) m))
        (else (remainder (* base (expmod base (- exp 1) m)) m))))

(define (report-prime n elapsed-time)
  (newline)
  (display n)
  (display " *** ")
  (display elapsed-time))


(define (search-for-primes start last)
   (define (prime-iter cur last)
     (when (<= cur last) (timed-prime-test cur))
     (when (<= cur last) (prime-iter (+ cur 2) last)))
   (prime-iter (if (even? start) (+ start 1) start) last)) 
     
   
   