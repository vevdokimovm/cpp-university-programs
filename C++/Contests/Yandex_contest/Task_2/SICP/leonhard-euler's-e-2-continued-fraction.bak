#lang racket

(define (e n d k)
  (define (iter current result)
    (cond ((= k current) (iter (- current 1) (/ (n (- current 1)) (+ (d (- current 1)) (/ (n current) (d current))))))
          ((= current 0) (+ 2 result))
          (else (iter (- current 1) (/ (n current) (+ result (d current)))))))
  (if (= k 1) 
      (/ (n k) (d k))
      (iter k 0)))

(define (n i)
  1.0)

(define (d i)
  (cond ((= i 1) 1)
        ((= i 2) 2)
        ((= (remainder i 3) 0) 1)
        ((= (remainder i 3) 1) 1)
        (else (if (= (remainder (- i 2) 2) 0)
                  (- i 2)
                  (- i 1)))))
