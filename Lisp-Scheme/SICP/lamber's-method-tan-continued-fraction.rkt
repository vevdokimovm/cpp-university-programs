#lang racket

(define (square x) (* x x))

(define (cont-frac n d k)
  (define (iter current result)
    (cond ((= k current) (iter (- current 1) (* 1.0 (/ (n (- current 1)) (+ (d (- current 1)) (/ (n current) (d current)))))))
          ((= current 0) result)
          (else (iter (- current 1) (* 1.0 (/ (n current) (+ result (d current))))))))
  (if (= k 1) 
      (/ (n k) (d k))
      (iter k 0)))

(define (tan-cf x k)
  (cont-frac (lambda (i)
                (if (= i 1)
                    x
                    (- (square x))))
              (lambda (i)
                (- (* 2 i) 1))
              k))