#lang racket

(define (cube x) 
  (* x x x))

(define (inc x)
  (+ x 1))

(define (identity x) x)

(define (sum-cubes a b)
  (sum1 cube a inc b)) 

(define (sum-integers a b)
  (sum1 identity a inc b))

(define (sum fun a next b)
  (if (> a b)
      0
      (+ (fun a)
         (sum fun (next a) next b))))

(define (sum1 term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a) (+ result (term a)))))
  (iter a 0))
        