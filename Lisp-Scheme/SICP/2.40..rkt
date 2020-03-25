#lang racket

(define (enumerate-interval low high)
  (if (> low high)
      null
      (cons low (enumerate-interval (+ low 1) high))))

(define (accumulate op initial seq)
  (if (null? seq)
      initial
      (op (car seq)
          (accumulate op initial (cdr seq)))))

(define (unique-pairs n)
  (accumulate append
              null
              (map (lambda (i) 
                     (map (lambda (j) (list i j)) 
                          (enumerate-interval 1 (- i 1)))) 
                   (enumerate-interval 1 n))))

(define (make-pair-sum pair)
  (list (car pair) (cadr pair) (+ (car pair) (cadr pair))))

(define (filter valid? seq)
  (cond ((null? seq) null)
        ((valid? (car seq)) 
         (cons (car seq) (filter valid? (cdr seq))))
        (else 
         (filter valid? (cdr seq)))))

(define (next divisior)
  (if (= divisior 2)
      3
      (+ divisior 2)))

(define (square x) (* x x))

(define (prime? num)
  (define (iter divisior)
    (cond ((> (square divisior) num) #t)
          ((= (remainder num divisior) 0) #f)
          (else (iter (next divisior)))))
  (iter 2))

(define (prime-sum? pair)
  (prime? (+ (car pair) (cadr pair))))

(define (prime-sum-pairs n)
  (map make-pair-sum
       (filter prime-sum?
               (unique-pairs n))))