#lang racket

(define (pseudoremainder-terms p q)
  (let ((integ-factor (expt (coeff (first-term q)) (+ 1 (order (first-term p)) (- (order (first-term q)))))))
    (cadr (div-terms (mul p integ-factor)
                     q))))

(define (gcd-terms a b)
  (if (empty-termlist? b)
      (let ((g (gcd  (first-term a)
                     (fisrt-term (rest-terms a)))))
        (make-poly (variable a)
                   (map (lambda (x) (/ x g)) (term-list))))
      (gcd-terms b (pseudoremainder-terms a b))))